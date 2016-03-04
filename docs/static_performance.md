# Static Performance Report

### Tools Used
Yslow, Pagespeed Tools

The suggestions these two tools gave us had the least amount of overlap, so therefore we felt that together they provided a good general measurement of our optimizations

### Initial state of the site
These are the results for the incidents timeline/table page. The other pages were all as good or better.

When using Yslow, our site actually recieved an A as the original score, although it was the lowest A possible (90).  There were 4 change suggestions that we did not get an A on.
* F - use a CDN
* F - expires headers
* B - compress componentents with gzip
* C - use cookie-free domain

When running Pagespeed we recieved an 88% for desktop.  There were also 4 suggestions
* render browser caching
* remove blocking JS
* enable compression with gzip
* minify javascript


### Discussion of Changes
Th


### Final Results
