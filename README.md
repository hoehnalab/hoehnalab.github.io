
# Höhna Lab Website

This is the repository containing the source code for the [Höhna Lab website](https://hoehnalab.github.io/) at Ludwig-Maximilians-Universität München (LMU). The site is built using the Jekyll static site generator.

## Running the Site Locally
To view or edit the website on your local machine, you need to have Ruby and Jekyll installed. The repository includes a simple `deploy.sh` script to simplify the process of running the website on your local machine for development and content editing.

### Prerequisites
**Ruby and Bundler**: Follow the official [Jekyll installation guide](https://jekyllrb.com/docs/installation/) for your operating system to install Ruby and the Bundler gem.

Running the site with the script
1. Clone the repository and navigate into the directory
2. Run the script:
   The `deploy.sh` script performs two steps:
   - It runs `bundle install` to install all the necessary software packages (gems).
   - It runs `bundle exec jekyll serve` to build the website and start a local server.
3. View the site:
   Once the script is running, open your web browser and navigate to `http://localhost:4000`. The website will automatically refresh whenever you save a change to a file.
   **Note:** Despite its name, the `deploy.sh` script is for local development only. Running it will not update the live, public website. For that you need to push the changes to GitHub.

## Updating Content
Most of the website's content can be updated by editing Markdown (`.md`) files.

## Powered by Thinkspace Theme

Thinkspace is a minimalist Jekyll theme designed for technical writing and blogs.

For more information on the theme, visit its repository: https://heiswayi.github.io/thinkspace/


### License

[MIT License](LICENSE.md)
