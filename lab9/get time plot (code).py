import numpy as np
import matplotlib.pyplot as plt
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20],
          [42.1, 40.5, 29.4, 29.3, 37.4, 38.8, 42.0, 31.9, 40.7, 41.7, 40.5,
           43.0, 46.1, 42.6, 42.6, 39.4, 43.0, 44.1, 32.4, 45.1])

plt.xlabel(r'$data \; size, 10^3$')
plt.ylabel(r'$nsec \; 10^3$')
plt.ylim(0, 100);
plt.xlim(1, 20);
plt.title(r'$time\;it\;takes\;to\;get\;an\;element$')
plt.grid(True)
plt.savefig('get element.png')
plt.show()
