from graphviz import Digraph


def generate_large_nfa():
    nfa = Digraph("NFA")

    states = [f"q{i}" for i in range(10)]
    alphabet = ["a", "b", "c"]

    # Add states
    for state in states:
        nfa.node(state)

    # Define initial and final states
    nfa.node("q0", shape="doublecircle")  # Start state
    nfa.node("q9", shape="doublecircle")  # Final state

    # Add transitions
    nfa.edge("q0", "q1", "a")
    nfa.edge("q0", "q2", "b")
    nfa.edge("q1", "q3", "a")
    nfa.edge("q1", "q4", "b")
    nfa.edge("q2", "q4", "b")
    nfa.edge("q3", "q5", "b")
    nfa.edge("q4", "q6", "a")
    nfa.edge("q5", "q7", "b")
    nfa.edge("q6", "q8", "b")
    nfa.edge("q7", "q9", "a")
    nfa.edge("q8", "q9", "λ")

    nfa.edge("q9", "q2", "λ")

    # Add some epsilon transitions
    nfa.edge("q0", "q5", "λ")
    nfa.edge("q2", "q6", "λ")
    nfa.edge("q3", "q8", "λ")

    return nfa


nfa = generate_large_nfa()
nfa.render("large_nfa", format="png", cleanup=False)
