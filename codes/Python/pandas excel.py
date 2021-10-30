import pandas as pd
from pandas import ExcelWriter
from pandas import ExcelFile
with pd.ExcelFile('C:/Users/Anand/pandas.xlsx', engine="openpyxl") as excel:
    dataframe = pd.read_excel(excel)

#df = pd.read_excel('C:/Users/Anand/pandas.xlsx', sheet_name='Sheet1',engine='openpyxl')

print("Column headings:")
print(df.columns)

