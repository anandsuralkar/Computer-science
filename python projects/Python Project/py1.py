import pandas as pd

excel_writer="C:/Users/Anand/OneDrive/Desktop/Git/Python Project/sheets.xls"
df= pd.DataFrame([['a', 'b'], ['c', 'd']],
                   index=['row 1', 'row 2'],
                   columns=['col 1', 'col 2'])
df.to_excel(excel_writer)
df.to_excel(excel_writer,sheet_name="sheet1")


print("success")
