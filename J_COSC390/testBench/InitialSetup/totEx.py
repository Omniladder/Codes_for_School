"""
    This is simply experimental
"""

import typing
import os

from langchain_openai import ChatOpenAI
from langchain_experimental.tot.base import ToTChain


open_ai_key = os.getenv("OPEN_AI_KEY")
llm = ChatOpenAI(model="gpt-4o-mini", api_key=open_ai_key)

tot_model = ToTChain(llm=llm, checker=)

print(llm.invoke("Hello how are you?").content)

# tree_object = ToTChain()
