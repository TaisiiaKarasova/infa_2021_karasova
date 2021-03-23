import numpy as np
import matplotlib.pyplot as plt
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [31555500, 81043400, 146740200, 230872000, 334083700, 450094700,
           590097000, 756049400, 962761000, 1186151500],
          label=r'$add \; element \; begin$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [5111800, 14512400, 14876700, 28610000, 31294200, 31519500,
           31002600, 34632800, 39024000, 43132500],
          label=r'$create \; + \; fill$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [5010200, 9558800, 14115400, 19919000, 23656200, 28571800,
           33010200, 38669600, 42476300, 47475100],
          label=r'$add \; element \; end$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [200, 200, 200, 200, 200, 200, 200, 200, 200, 200],
          label=r'$reffer \; by \; number$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [39086900, 85789200, 141985400, 210499800, 285827700,
           370323600, 455363900, 559967100, 667616500, 783263100],
          label=r'$add \; element \; middle$')
plt.xlabel(r'$data \; size, 10^4$')
plt.ylabel(r'$nsec$')
plt.title(r'$vector \; different \; processes$')
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.savefig('vector different processes.png')
plt.show()
