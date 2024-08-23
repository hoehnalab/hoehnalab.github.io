#!/bin/bash 

# install all tthe necessary gems
bundle install 

# deploy
bundle exec jekyll serve 
