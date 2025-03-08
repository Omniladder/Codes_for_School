import typing
import json


def mathQATest(startIndex: int, endIndex: int) -> int:  # Outputs average
    fileLocation = "./math_qa/test.json"
    file = open(fileLocation)
    questionData = json.load(file)

    # keys = questionData[0].keys()

    for question in questionData[startIndex:endIndex]:
        # print(keys)
        print(question["Rationale"])


mathQATest(5, 10)
