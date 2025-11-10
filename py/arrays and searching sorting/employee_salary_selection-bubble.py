# List of employee salaries
salaries = [55000.5, 72000.75, 48000.25, 91000.0, 66000.4,
            83000.9, 39000.0, 102000.25, 58000.1, 47000.8]

n = len(salaries)

# ---- SELECTION SORT ----
selection_sorted = salaries.copy()
for i in range(n - 1):
    min_index = i
    for j in range(i + 1, n):
        if selection_sorted[j] < selection_sorted[min_index]:
            min_index = j
    # Swap
    selection_sorted[i], selection_sorted[min_index] = selection_sorted[min_index], selection_sorted[i]

print("Salaries sorted using Selection Sort (Ascending):")
print(selection_sorted)
print()

# ---- BUBBLE SORT ----
bubble_sorted = salaries.copy()
for i in range(n - 1):
    for j in range(0, n - i - 1):
        if bubble_sorted[j] > bubble_sorted[j + 1]:
            # Swap
            bubble_sorted[j], bubble_sorted[j + 1] = bubble_sorted[j + 1], bubble_sorted[j]

print("Salaries sorted using Bubble Sort (Ascending):")
print(bubble_sorted)
print()

# ---- TOP 5 HIGHEST SALARIES ----
# The list is already sorted in ascending order, so take last 5 elements
top_5 = selection_sorted[-5:]

print("Top 5 Highest Salaries:")
for salary in reversed(top_5):  # Print from highest to lowest
    print(salary)
