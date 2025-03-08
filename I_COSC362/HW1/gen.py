from graphviz import Digraph


def question8():
    nfa = Digraph("DFA")

    nfa.attr(rankdir="LR")

    nfa.node("q2", shape="doublecircle")

    nfa.edge("q0", "q0", "0")
    nfa.edge("q0", "q1", "1")
    nfa.edge("q4", "q4", "1")

    nfa.edge("q1", "q2", "1")
    nfa.edge("q2", "q3", "1")
    nfa.edge("q3", "q4", "1")

    nfa.edge("q1", "q0", "0")
    nfa.edge("q2", "q1", "0")
    nfa.edge("q3", "q2", "0")
    nfa.edge("q4", "q3", "0")

    nfa.node("start", label="", shape="point", width="0")
    nfa.edge("start", "q2")

    nfa.render("question_8", format="png", cleanup=True)


def question4():
    nfa = Digraph("DFA")

    nfa.attr(rankdir="LR")

    nfa.node("q5", shape="doublecircle")

    nfa.edge("q0", "q1", "a")
    nfa.edge("q1", "q2", "b")
    nfa.edge("q2", "q3", "b")
    nfa.edge("q3", "q3", "a")
    nfa.edge("q3", "q4", "b")
    nfa.edge("q4", "q3", "a")
    nfa.edge("q4", "q5", "b")
    nfa.edge("q5", "q3", "a")
    nfa.edge("q6", "q6", "a,b")
    nfa.edge("q0", "q6", "b")
    nfa.edge("q1", "q6", "a")
    nfa.edge("q2", "q6", "a")

    nfa.node("start", label="", shape="point", width="0")
    nfa.edge("start", "q0")

    nfa.render("question_4", format="png", cleanup=True)


def question5():
    nfa = Digraph("DFA")

    nfa.attr(rankdir="LR")

    nfa.node("q1", shape="doublecircle")

    nfa.edge("q0", "q4", "a,b")
    nfa.edge("q4", "q1", "a,b")
    nfa.edge("q1", "q2", "a,b")
    nfa.edge("q2", "q3", "a,b")
    nfa.edge("q3", "q1", "a,b")

    nfa.node("start", label="", shape="point", width="0")
    nfa.edge("start", "q0")

    nfa.render("question_5", format="png", cleanup=True)


def question6():
    nfa = Digraph("DFA")

    # nfa.attr(rankdir="LR")

    with nfa.subgraph() as row1:
        row1.attr(rank="same")  # Forces these nodes to be in the same horizontal row
        row1.node("q0")
        row1.node("q1")
        row1.node("q2")

    with nfa.subgraph() as row2:
        row2.attr(rank="same")
        row2.node("q3")
        row2.node("q4")
        row2.node("q5")

    with nfa.subgraph() as row3:
        row3.attr(rank="same")
        row3.node("q6")
        row3.node("q7")
        row3.node("q8")

    nfa.node("q1", shape="doublecircle")
    nfa.node("q2", shape="doublecircle")
    nfa.node("q4", shape="doublecircle")

    nfa.edge("q0", "q1", "b")
    nfa.edge("q1", "q2", "b")
    nfa.edge("q2", "q0", "b")

    nfa.edge("q3", "q4", "b")
    nfa.edge("q4", "q5", "b")
    nfa.edge("q5", "q3", "b")

    nfa.edge("q6", "q7", "b")
    nfa.edge("q7", "q8", "b")
    nfa.edge("q8", "q6", "b")

    nfa.edge("q0", "q3", "a")
    nfa.edge("q1", "q4", "a")
    nfa.edge("q2", "q5", "a")

    nfa.edge("q3", "q6", "a")
    nfa.edge("q4", "q7", "a")
    nfa.edge("q5", "q8", "a")

    nfa.edge("q6", "q0", "a")
    nfa.edge("q7", "q1", "a")
    nfa.edge("q8", "q2", "a")

    nfa.node("start", label="", shape="point", width="0")
    nfa.edge("start", "q0")

    nfa.render("question_6", format="png", cleanup=True)


def question7():
    nfa = Digraph("DFA")

    nfa.attr(rankdir="LR")

    nfa.node("q0", shape="doublecircle")

    nfa.edge("q0", "q1", "a,b")
    nfa.edge("q1", "q2", "a,b")
    nfa.edge("q2", "q0", "a,b")

    nfa.node("start", label="", shape="point", width="0")
    nfa.edge("start", "q0")

    nfa.render("question_7", format="png", cleanup=True)


question4()
question5()
question6()
question7()
question8()
