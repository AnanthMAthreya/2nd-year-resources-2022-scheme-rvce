import sys

N = 4  # Change this value based on the number of tasks/agents

def calculate_cost(cost_matrix, assigned, task):
    min_cost = sys.maxsize
    for i in range(N):
        if not assigned[i] and cost_matrix[task][i] < min_cost:
            min_cost = cost_matrix[task][i]
    return min_cost

def branch_and_bound(cost_matrix, assigned, current_agent, current_cost, best_cost):
    if current_agent == N:
        return min(current_cost, best_cost)
    
    for i in range(N):
        if not assigned[i]:
            assigned[i] = True

            new_cost = current_cost + cost_matrix[current_agent][i]
            lower_bound = new_cost

            for j in range(current_agent + 1, N):
                lower_bound += calculate_cost(cost_matrix, assigned, j)

            if lower_bound < best_cost:
                best_cost = branch_and_bound(cost_matrix, assigned, current_agent + 1, new_cost, best_cost)

            assigned[i] = False

    return best_cost

cost_matrix = [[10, 19, 8, 15],[10, 18, 7, 17],[13, 16, 9, 14],[12, 19, 8, 18]]
assigned = [False] * N  # Tracks which tasks are assigned (False: unassigned, True: assigned)
best_cost = sys.maxsize
best_cost = branch_and_bound(cost_matrix, assigned, 0, 0, best_cost)

print(f"Minimum cost: {best_cost}")




