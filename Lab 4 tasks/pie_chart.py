import matplotlib.pyplot as plt
import pandas as pd
df = pd.read_csv('hourlySteps_merged.csv' )
print(df.dtypes)
list1 = df['Calories'].values.tolist()
list2 = df['SedentaryActiveDistance'].values.tolist()
plt.pie(list1,list2)
plt.show()