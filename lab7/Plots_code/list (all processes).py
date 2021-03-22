import numpy as np
import matplotlib.pyplot as plt
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [14316200, 27885300, 41879300, 56293800, 70686800, 85092900,
           100516300, 116900000, 127504100, 146508200],
          label=r'$add \; element \; begin$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [23536200, 38728700, 55734400, 81310300, 82570400, 107265700,
           97798200, 110793600, 126350400, 141941900],
          label=r'$create \; + \; fill$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [14129700, 28422900, 42249400, 56644400, 70739400, 87177500,
           99769000, 114593900, 130114900, 146005300],
          label=r'$add \; element \; end$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [11036800, 21972200, 32964500, 44435600, 55237400, 66158500,
           78057500, 88739300, 100844200, 113970400],
          label=r'$reffer \; by \; number$')
plt.xlabel(r'$data \; size, 10^4$')
plt.ylabel(r'$nsec$')
plt.title(r'$list \; different \; processes$')
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.savefig('list different processes.png')
plt.show()
