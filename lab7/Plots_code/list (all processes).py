import numpy as np
import matplotlib.pyplot as plt
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [14464200, 28904900, 44674500, 59354800, 74987600, 89246800,
            105648100, 120399100, 135754500, 155187800],
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
          [56894200, 231830300, 520285300, 954218100, 1541504900,
           2329490900, 3918153100, 5099601900, 5414722500, 6680786700],
          label=r'$add \; element \; middle$')
plt.xlabel(r'$data \; size, 10^4$')
plt.ylabel(r'$nsec$')
plt.title(r'$list \; different \; processes$')
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.savefig('list different processes.png')
plt.show()
