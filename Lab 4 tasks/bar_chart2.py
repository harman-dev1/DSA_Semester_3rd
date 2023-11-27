import matplotlib.pyplot as plt
import pandas as pd
df = pd.read_csv('dailyActivity_merged.csv' )
print(df.dtypes)
list1 = df['Calories'].values.tolist()
list2 = df['SedentaryActiveDistance'].values.tolist()
plt.bar(list1, list2,width = 1, color = ['black', 'green'])
plt.show()