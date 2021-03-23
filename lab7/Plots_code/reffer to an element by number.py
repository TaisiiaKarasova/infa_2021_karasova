import numpy as np
import matplotlib.pyplot as plt
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [200, 200, 200, 200, 200, 200, 200, 200, 200, 200],
          label=r'$vector$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [1037500, 2126600, 3236400, 4501000, 5908300, 7058300, 9039300,
           9635600, 11057800, 12267800],
          label=r'$list$')
plt.xlabel(r'$data \; size, 10^4$')
plt.ylabel(r'$nsec$')
plt.title(r'$reffer \; to \; an \; element \; by \; number$')
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.savefig('reffer to an element by number.png')
plt.show()
