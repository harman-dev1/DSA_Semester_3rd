import matplotlib.pyplot as plt
import pandas as pd
df = pd.read_csv('dailyActivity_merged.csv' )
print(df.dtypes)
list1 = df['TotalSteps'].values.tolist()
list2 = df['Id'].values.tolist()
plt.plot(list1,list2)
plt.show()