def print_state(state):
    for row in state:
        print(" ".join(map(str, row)))
    print()

def find_blank(state):
    for i in range(3):
        for j in range(3):
            if state[i][j] == 0:
                return i, j

def move(state, direction):
    i, j = find_blank(state)
    new_state = [row[:] for row in state]  # Copy list

    if direction == "up" and i > 0:
        new_state[i][j], new_state[i-1][j] = new_state[i-1][j], new_state[i][j]
        return new_state
    if direction == "down" and i < 2:
        new_state[i][j], new_state[i+1][j] = new_state[i+1][j], new_state[i][j]
        return new_state
    if direction == "left" and j > 0:
        new_state[i][j], new_state[i][j-1] = new_state[i][j-1], new_state[i][j]
        return new_state
    if direction == "right" and j < 2:
        new_state[i][j], new_state[i][j+1] = new_state[i][j+1], new_state[i][j]
        return new_state
    return None

def heuristic(state, goal_state):
    return sum(1 for i in range(3) for j in range(3) if state[i][j] != goal_state[i][j])

def a_star(initial_state, goal_state):
    OPEN = [[heuristic(initial_state, goal_state), 0, initial_state]]
    CLOSED = []

    while OPEN:
        OPEN.sort()  # Sort by f = g + h
        f, g, current_state = OPEN.pop(0)
        
        print_state(current_state)

        if current_state == goal_state:
            print("Solution found!")
            return

        CLOSED.append(current_state)

        for direction in ["up", "down", "left", "right"]:
            successor = move(current_state, direction)
            if successor and successor not in CLOSED:
                h = heuristic(successor, goal_state)
                OPEN.append([g + 1 + h, g + 1, successor])

    print("Solution not found")

# Example Usage
initial_state = [
    [1, 2, 3],
    [8, 0, 4],
    [7, 6, 5]
]

goal_state = [
    [1, 2, 0],
    [8, 6, 3],
    [7, 5, 4]
]

a_star(initial_state, goal_state)