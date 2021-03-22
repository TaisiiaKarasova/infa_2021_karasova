import numpy as np
import matplotlib.pyplot as plt
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [31555500, 81043400, 146740200, 230872000, 334083700, 450094700,
           590097000, 756049400, 962761000, 1186151500],
          label=r'$vector$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [14316200, 27885300, 41879300, 56293800, 70686800, 85092900,
           100516300, 116900000, 127504100, 146508200],
          label=r'$list$')
plt.xlabel(r'$data \; size, 10^4$')
plt.ylabel(r'$nsec$')
plt.title(r'$addition \; of \; an \; element \; to \; the \; beginning$')
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.savefig('add an element (begin).png')
plt.show()
