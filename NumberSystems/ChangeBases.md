### Change a  number from a base ob to a base od.
* Time Complexity Worst case: )
* Time Complexity Best Case: )

| Case          | Time Complexity |
| ------------- |:---------------:|
| Worst Case    | O(8(n)          |
| Best Case     | O(3(n)          |

```python   
""" CHANGE THE BASE OF A NUMBER
    ob -> origin base
    od -> destiny base
"""
def changeBase(number, ob,od):
    if ob == 10:
        return tob(number, od)
    return tob(to10(number,ob),od)

""" FROM ANY BASE TO BASE 10
    b -> base of the number n
    pos -> location of a sub-number in n
"""
def to10(n, b, pos =0):
   if n == 0: return 0
   return (n % 10)* (b  ** pos) + to10(n / 10, b, pos+1)

"""FROM TEN BASE TO ANOTHER BASE"""
def tob(n, b):
    if n == 0: return ""
    return   tob(n // b, b) + str(n % b)
```