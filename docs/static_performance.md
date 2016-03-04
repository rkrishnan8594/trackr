# Static Performance Report

### Tools Used
Yslow, Pagespeed Tools

The suggestions these two tools gave us had the least amount of overlap, so therefore we felt that together they provided a good general measurement of our optimizations

### Initial state of the site
These are the results for the incidents timeline/table page. The other pages were all as good or better.

When using Yslow, our site actually recieved an A as the original score, although it was the lowest A possible (90).  There were 4 change suggestions that we did not get an A on.
* F - use a CDN
* F - expires headers
* B - compress components with gzip
* C - use cookie-free domain

When running Pagespeed we recieved an 88% for desktop.  There were also 4 suggestions
* render browser caching
* remove blocking JS
* enable compression with gzip
* minify javascript


### Discussion of Changes
The first change we made was to components with gzip.  After some research about rails asset pipeline, we found that doing this was as simple as adding "use Rack::Deflater" to our config file.  This solved the issue for both of our tools

The next big change we made was setting up a CDN to serve our static content.  We decided to use S3 buckets in AWS to store our static content/images.  The main reason we decided to use S3 was that we read s3 is a bit slower than some cdns such as Cloudfront, but has better storage and bandwidth costs, which is something we felt we wanted to prioritize.  This brought our CDN grade on Yslow up to an A.

We found that solving the remove blocking JS from pagespeed was as simple as moving javascript to the bottom of the page.  we also minified our js using the uglifier gem

The next change we made was to add expires headers.  the way we did this was to add "config.static_cache_control = "public, max-age=31536000"" to our application.rb file in config.  This adds a far future expiring header to our files.  However we found that this did not help for the datatables gem we used to style our table with sorting, pagination, search, etc.  Because these files were unaffected, we were still receiving an F for the expires headers grade.  

We spent a lot of time trying to deal with this, but we found it very tricky to deal with the dataTables gem.  Eventually the idea we had to fix this was to instead of using datatables as a gem, reference the stylesheets and js files for the plug in externally since we found ones that were already on a CDN somewhere.  This method solved our expiration problems with the plug in on Yslow, upgrading that to an A, but it caused additional ones as well - the tags of some of the images in the CDN were not configured correctly.  This fell to a C.  Since this was lower on the list it resulted in an increase in performance, but it is another issue we have not solved yet.  it also caused an issue in pagespeed, which is that these sheets were considered render-blocking CSS and it wanted to be elimated.


### Final Results
