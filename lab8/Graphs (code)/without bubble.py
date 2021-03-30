import numpy as np
import matplotlib.pyplot as plt

plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [707900, 2971400, 6391400, 11663600, 18005400, 26364100,
           35492500, 46873600, 58837400, 78871500],
          label=r'$Insertion$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [1634900, 6184800, 13871300, 24506200, 39017700, 56193000,
           76091400, 98352000, 122155000, 153707000],
          label=r'$Selection$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [1471200, 3084800, 4970800, 6747700, 8817100, 11114800, 12799400,
            14829200, 17483500, 19015600],
          label=r'$Pyramide$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [436500, 837200, 1300100, 1796800, 2144200, 2712100, 3133400,
           3656400, 3969300, 4464200],
          label=r'$Merge$')

plt.xlabel(r'$data \; size, 10^3$')
plt.ylabel(r'$nsec$')
plt.title(r'$sort$')
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.savefig('sort.png')
plt.show()
