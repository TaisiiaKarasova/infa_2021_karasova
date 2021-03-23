import numpy as np
import matplotlib.pyplot as plt
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [39086900, 85789200, 141985400, 210499800, 285827700,
           370323600, 455363900, 559967100, 667616500, 783263100],
          label=r'$vector$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [3683357216, 3901641235, 2526241523, 3776607703, 2156045779,
           54235200, 2703748907, 1334470484, 3555985207, 102121400],
          label=r'$list$')
plt.xlabel(r'$data \; size, 10^4$')
plt.ylabel(r'$nsec$')
plt.title(r'$addition \; of \; an \; element \; to \; the \; middle$')
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.savefig('add an element (middle).png')
plt.show()
