import matplotlib.pyplot as plt
import matplotlib.animation as animation

fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

def animate(i):
    data = open('data.txt', 'r').read()
    lines = data.split('\n')
    xs = []
    ys = []

    for line in lines:
        var = line.split(',')
        xs.append(float(var[0]))
        ys.append(float(var[1]))
    ax.clear()
    ax.plot(xs, ys)

    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('График')

ani = animation.FuncAnimation(fig, animate, interval=10000)
plt.show()
