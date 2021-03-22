import numpy as np
import matplotlib.pyplot as plt
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [200, 200, 200, 200, 200, 200, 200, 200, 200, 200],
          label=r'$vector$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [11036800, 21972200, 32964500, 44435600, 55237400, 66158500,
           78057500, 88739300, 100844200, 113970400],
          label=r'$list$')
plt.xlabel(r'$data \; size, 10^4$')
plt.ylabel(r'$nsec$')
plt.title(r'$reffer \; to \; an \; element \; by \; number$')
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.savefig('reffer to an element by number.png')
plt.show()
