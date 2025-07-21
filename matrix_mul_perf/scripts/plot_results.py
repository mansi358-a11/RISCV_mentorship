import matplotlib.pyplot as plt

naive_time = 4.3  # Replace with actual result
tiled_time = 2.7  # Replace with actual result

labels = ['Naive', 'Tiled']
times = [naive_time, tiled_time]

plt.bar(labels, times, color=['red', 'green'])
plt.ylabel('Time (seconds)')
plt.title('Matrix Multiplication Performance')
plt.savefig('matrix_perf.png')
plt.show()
