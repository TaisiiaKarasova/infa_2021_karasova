import numpy as np
import matplotlib.pyplot as plt
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [7117100, 14969900, 15160400, 20173400, 374806200, 34806200,
           32710100, 36432000, 40145000, 44178900],
          label=r'$vector$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [23536200, 38728700, 55734400, 81310300, 82570400, 107265700,
           97798200, 110793600, 126350400, 141941900],
          label=r'$list$')
plt.xlabel(r'$data \; size, 10^4$')
plt.ylabel(r'$nsec$')
plt.title(r'$creating \; and \; filling \; the \; structure$')
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.savefig('creating and filling the structure.png')
plt.show()
