import numpy as np
import matplotlib.pyplot as plt
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [31555500, 81043400, 146740200, 230872000, 334083700, 450094700,
           590097000, 756049400, 962761000, 1186151500],
          label=r'$add \; element \; begin$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [7117100, 14969900, 15160400, 20173400, 374806200, 34806200,
           32710100, 36432000, 40145000, 44178900],
          label=r'$create \; + \; fill$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [5010200, 9558800, 14115400, 19919000, 23656200, 28571800,
           33010200, 38669600, 42476300, 47475100],
          label=r'$add \; element \; end$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [200, 200, 200, 200, 200, 200, 200, 200, 200, 200],
          label=r'$reffer \; by \; number$')
plt.xlabel(r'$data \; size, 10^4$')
plt.ylabel(r'$nsec$')
plt.title(r'$vector \; different \; processes$')
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.savefig('vector different processes.png')
plt.show()
