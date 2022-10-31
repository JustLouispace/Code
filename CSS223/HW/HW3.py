# Multi-column-sorting

import pandas as pd

No = ({
    'A':[1,3,4,2,3,4,1,2,3,1,1,4,5,3],
    'B':[1,1,4,4,5,3,3,4,3,5,1,1,2,5],
    'C':[4,1,4,4,3,3,3,3,5,3,4,1,3,2]
               })
df = pd.DataFrame(No)
print(df)

df2 = df.sort_values(['A','B','C'], ascending=[True, True, True])
print(df2)