import numpy as np
import matplotlib.pyplot as plt
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [440700, 1027600, 1819900, 2745200, 3838100, 5157700, 6861900,
           8915600, 12775800, 12005700],
          label=r'$vector$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [56894200, 231830300, 520285300, 954218100, 1541504900,
           2329490900, 3918153100, 5099601900, 5414722500, 6680786700],
          label=r'$list$')
plt.xlabel(r'$data \; size, 10^4$')
plt.ylabel(r'$nsec$')
plt.title(r'$addition \; of \; an \; element \; to \; the \; middle$')
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.savefig('add an element (middle).png')
plt.show()
