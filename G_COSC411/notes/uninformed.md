# Uninformed Search

## Search Methods
- Breadth first search
- Depth First Search
- Uniform-Cost Search

### Interactions
- Perception | Sensors
- Acts | Actuators

## Rationality
- Attempt to maximize expected utility
- 2 Designes
    - Keeps Track of Two Things
        - Goal
        - Cost
        - Reach Goal at Minimum Cost
    - Keeps track of Numerical
        - Utility
        - Reward
        - MMaximizes Profit
- Reach Goal with Lowest Cost
- Maximize Profit 

### Environments require different bots
- Fully/Partially observable   |  requires memory
- Discrete vs continous cannot |  enumerate all states
- Stochastic vs Deterministic  |  preparations needed for continguincies
- Single Agent vs Multi agent  |  may behave randomly


## Reflex Agent
- Chooses action based on how world **IS**
- Choose action based on perception
- Doesn't consider future consequences

## Planning Agent
- Makes Decisions based on hypothesized consequences
- Has model of how world evolves
- Consider how world **Would Be**


## Search Problem
Contains:
- State Space
- Successor function such as actions and costs
- Start State and Goal

Search Problem is a Model

#### Solution
Solution - A plan which transforms start state to goal state

## World State
Contains:
Every Detail of environment

##### Search State
Contains
Details needed for Planning
