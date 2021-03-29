import numpy as np
import matplotlib.pyplot as plt
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [5111800, 14512400, 14876700, 28610000, 31294200, 31519500,
           31002600, 34632800, 39024000, 43132500],
          label=r'$vector$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [36668600, 51806700, 85365800, 156285500, 179192800, 127577700,
           150497000, 173620900, 193991600, 216578100],
          label=r'$list$')
plt.xlabel(r'$data \; size, 10^4$')
plt.ylabel(r'$nsec$')
plt.title(r'$creating \; and \; filling \; the \; structure$')
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.savefig('creating and filling the structure.png')
plt.show()
