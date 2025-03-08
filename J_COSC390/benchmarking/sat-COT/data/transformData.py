import pandas as pd
from jinja2 import Template
import json

# Read the Parquet file into a DataFrame
df = pd.read_parquet("train-00000-of-00001.parquet")

# Display the first few rows

# print(df)


prompt = Template(
    source="""
    You are a Problem Solving Assistant. Your task is to break down mathematical and logical problems into smaller, manageable steps. You will be provided with:
    - The original problem statement
    - The current progress/reasoning

    If you run out of space to explain, provide your final answer in the following format:

    \\answer[ANSWER]

    Current state of the problem:
    Problem:
    {{ problem }}

    Reasoning:
    {% for reason in reasoning %}
        Step {{ loop.index }}: {{ reason }}
    {% endfor %}

"""
)

df = df[df["is_correct"]].reset_index(drop=True)

dataArray = []

for index, _ in enumerate(df["question"]):
    prevResponses = []
    question = df["question"][index]
    reasoning = df["reasoning_chain"][index]
    answer = df["answer"][index]

    for reason in reasoning["steps"]:

        currentKnowledge = prompt.render(problem=question, reasoning=prevResponses)
        dataArray.append({"input": currentKnowledge, "output": reason["explanation"]})
        prevResponses.append(reason["explanation"])

    currentKnowledge = prompt.render(problem=question, reasoning=prevResponses)
    dataArray.append({"input": currentKnowledge, "output": f"\\answer[{answer}]"})

with open("./COTTrainingData.json", "w", encoding="utf-8") as file:
    json.dump(dataArray, file)
