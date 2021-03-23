import numpy as np
import matplotlib.pyplot as plt
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [14316200, 27885300, 41879300, 56293800, 70686800, 85092900,
           100516300, 116900000, 127504100, 146508200],
          label=r'$add \; element \; begin$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [36668600, 51806700, 85365800, 156285500, 179192800, 127577700,
           150497000, 173620900, 193991600, 216578100],
          label=r'$create \; + \; fill$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [14129700, 28422900, 42249400, 56644400, 70739400, 87177500,
           99769000, 114593900, 130114900, 146005300],
          label=r'$add \; element \; end$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [1037500, 2126600, 3236400, 4501000, 5908300, 7058300, 9039300,
           9635600, 11057800, 12267800],
          label=r'$reffer \; by \; number$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [3683357216, 3901641235, 2526241523, 3776607703, 2156045779,
           54235200, 2703748907, 1334470484, 3555985207, 102121400],
          label=r'$add \; element \; middle$')
plt.xlabel(r'$data \; size, 10^4$')
plt.ylabel(r'$nsec$')
plt.title(r'$list \; different \; processes$')
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.savefig('list different processes.png')
plt.show()
