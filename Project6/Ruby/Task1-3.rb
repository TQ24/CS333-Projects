# CS333
# Project 6
#
# Extensions: Choose a third selected language
# read and download contents from internet(wiki)

require "open-uri"

base_url = "http://en.wikipedia.org/wiki"
page_name = "Kobe_Bryant"
full_url = base_url + "/" + page_name

data = open(full_url).read
download_file = open("Kobe-Bryant-wiki.html", "w")

download_file.write(data)
download_file.close
