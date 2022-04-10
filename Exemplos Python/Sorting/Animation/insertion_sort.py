import matplotlib.animation as animation
import matplotlib.pyplot as plt
import random

def swap(array, i, j):
    if i != j:
        array[i], array[j] = array[j], array[i]

def insertionsort(array):
    for i in range(1, len(array)):
        j = i
        while j > 0 and array[j - 1] > array[j]:
            swap(array, j, j - 1)
            j -= 1
            yield array

N = 40
array = [x + 1 for x in range(N)]
random.shuffle(array)
generator = insertionsort(array)
writergif = animation.PillowWriter(fps=30) 

fig, ax = plt.subplots()
plt.grid()

bar_rects = ax.bar(range(len(array)), array, align="edge", color='k')

ax.set_xlim(0, N)
ax.set_ylim(0, int(1.07 * N))

text = ax.text(0.02, 0.95, "", transform=ax.transAxes)

iteration = [0]
def update_fig(array, rects, iteration):
    for rect, val in zip(rects, array):
        rect.set_height(val)
    iteration[0] += 1
    text.set_text(f"N of operations: {iteration[0]}")

anim = animation.FuncAnimation(fig, func=update_fig,
    fargs=(bar_rects, iteration), frames=generator, interval=1,
    repeat=False, save_count=400)

anim.save('insertion.gif', writer=writergif)