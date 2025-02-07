"""
    This is simply experimental
"""

from typing import Tuple
import os
import regex as re

from langchain_openai import ChatOpenAI

from langchain_experimental.tot.base import ToTChain
from langchain_experimental.tot.checker import ToTChecker
from langchain_experimental.tot.thought import ThoughtValidity

open_ai_key = os.getenv("OPEN_AI_KEY")
llm = ChatOpenAI(model="gpt-4o-mini", api_key=open_ai_key)


sudoku_puzzle = "3,*,*,2|1,*,3,*|*,1,*,3|4,*,*,1"
sudoku_solution = "3,4,1,2|1,2,3,4|2,1,4,3|4,3,2,1"

problem_description = f"""
    {sudoku_puzzle}

    - This is a 4x4 Sudoku puzzle.
    - The * represents a cell to be filled.
    - The | character separates rows.
    - At each step, replace one or more * with digits 1-4.
    - There must be no duplicate digits in any row, column or 2x2 subgrid.
    - Keep the known digits from previous valid thoughts in place.
    - Each thought can be a partial or the final solution.
""".strip()


class MyChecker(ToTChecker):
    def evaluate(
        self, problem_description: str, thoughts: Tuple[str, ...] = ()
    ) -> ThoughtValidity:
        last_thought = thoughts[-1]
        clean_solution = last_thought.replace(" ", "").replace('"', "")
        regex_solution = clean_solution.replace("*", ".").replace("|", "\\|")
        if sudoku_solution in clean_solution:
            return ThoughtValidity.VALID_FINAL
        elif re.search(regex_solution, sudoku_solution):
            return ThoughtValidity.VALID_INTERMEDIATE
        else:
            return ThoughtValidity.INVALID


tot_model = ToTChain(llm=llm, checker=MyChecker)

tot_model.invoke(problem_description)
