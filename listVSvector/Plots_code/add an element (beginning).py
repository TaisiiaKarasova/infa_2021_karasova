import numpy as np
import matplotlib.pyplot as plt
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [438100, 1167800, 2367400, 3742400, 5567400, 7560100, 10719600,
           14397000, 18636000, 24142700],
          label=r'$vector$')
plt.plot( [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
          [14464200, 28904900, 44674500, 59354800, 74987600, 89246800,
            105648100, 120399100, 135754500, 155187800],
          label=r'$list$')
plt.xlabel(r'$data \; size, 10^4$')
plt.ylabel(r'$nsec$')
plt.title(r'$addition \; of \; an \; element \; to \; the \; beginning$')
plt.grid(True)
plt.legend(loc='best', fontsize=12)
plt.savefig('add an element (begin).png')
plt.show()
