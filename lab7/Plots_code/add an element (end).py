import numpy as np
import matplotlib.pyplot as plt
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [5010200, 9558800, 14115400, 19919000, 23656200, 28571800,
           33010200, 38669600, 42476300, 47475100],
          label=r'$vector$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [14129700, 28422900, 42249400, 56644400, 70739400, 87177500,
           99769000, 114593900, 130114900, 146005300],
          label=r'$list$')
plt.xlabel(r'$data \; size, 10^4$')
plt.ylabel(r'$nsec$')
plt.title(r'$addition \; of \; an \; element \; to \; the \; end$')
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.savefig('add an element (end).png')
plt.show()
