# Import the necessary libraries
import pandas as pd
import matplotlib.pyplot as plt

# Load the data
cars_data = pd.read_csv("cars.csv")

# Create the histogram
plt.title('Histogram for distance travelled in KiloMeter')
counts, bins, patches = plt.hist(cars_data['KM'], color='green', edgecolor='white', bins=5)

# Add labels
plt.xlabel('Kilometer')
plt.ylabel('Frequency')

# Annotate the histogram with counts
for count, bin in zip(counts, bins):
    # Find the bin center for the annotation
    bin_center = bin + (bins[1] - bins[0]) / 2
    plt.text(bin_center, count, str(int(count)), ha='center', va='bottom')

# Show plot
plt.show()




########################################################


# Import libraries
import matplotlib.pyplot as plt
import pandas as pd

# Load the data
cars_data = pd.read_csv("Cars_Barplot.csv")
cars = cars_data["Car"]
data = cars_data["Sales"]

# Create the pie chart
fig = plt.figure(figsize=(10, 7))
plt.pie(data, labels=cars, autopct='%1.1f%%')  # Display percentage on the pie chart

# Show plot
plt.title('Pie Chart of Car Sales')
plt.show()
