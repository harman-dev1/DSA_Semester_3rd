import matplotlib.pyplot as plt
import pandas as pd
df = pd.read_csv('population_by_country_2020.csv' )
print(df.dtypes)
list1 = df['Country (or dependency)'].values.tolist()
list2 = df['Population (2020)'].values.tolist()
plt.bar(list1, list2,width = 1, color = ['black', 'green'])
plt.show()

#Scatter Chart

df = pd.read_csv('dailyActivity_merged.csv' )
print(df.dtypes)
list1 = df['TotalSteps'].values.tolist()
list2 = df['Id'].values.tolist()
plt.scatter(list1,list2)
plt.show()

#line chart

df = pd.read_csv('dailyActivity_merged.csv' )
print(df.dtypes)
list1 = df['TotalSteps'].values.tolist()
list2 = df['Id'].values.tolist()
plt.plot(list1,list2)
plt.show()

# pie chart 

df = pd.read_csv('hourlySteps_merged.csv' )
print(df.dtypes)
list1 = df['Calories'].values.tolist()
list2 = df['SedentaryActiveDistance'].values.tolist()
plt.pie(list1,list2)
plt.show()