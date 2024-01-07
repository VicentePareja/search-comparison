import matplotlib.pyplot as plt

# Initialize lists for divisors and averages
divisors = []
averages = []

# Read the data from the file
with open('averages.txt', 'r') as f:
    for line in f:
        divisor, avg = line.split(',')
        divisors.append(int(divisor))
        averages.append(float(avg))

# Create the plot
plt.plot(divisors, averages)
plt.title('Average Tries vs Divisor')
plt.xlabel('Divisor')
plt.ylabel('Average Number of Tries')
plt.show()
