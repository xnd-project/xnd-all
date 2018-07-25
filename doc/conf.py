import sys, os, docutils


extensions = [
    'sphinx.ext.intersphinx', 
    'sphinx.ext.doctest'
]

source_suffix = '.rst'
master_doc = 'index'
project = 'Plures'
copyright = '2017-2018, Plures Project'
version = 'v0.2.0dev3'
release = 'v0.2.0dev3'
exclude_patterns = ['doc', 'build']
pygments_style = 'sphinx'

html_static_path = ['_static']
templates_path = ['_templates']

primary_domain = 'py'
add_function_parentheses = False

html_theme = "sphinx_rtd_theme"
html_theme_path = ["_themes", ]

html_theme_options = {
    'canonical_url': '',
    'analytics_id': '',
    'logo_only': True,
    'display_version': True,
    'prev_next_buttons_location': 'bottom',
    'style_external_links': False,
    'vcs_pageview_mode': '',
    # Toc options
    'collapse_navigation': True,
    'sticky_navigation': True,
    'navigation_depth': 4,
    'includehidden': True,
    'titles_only': False,
    "relbarbgcolor": "black"
}

html_logo = "images/xndlogo.png"


def setup(app):
    app.add_crossref_type('topic', 'topic', 'single: %s',
                          docutils.nodes.strong)
    app.add_javascript("copybutton.js")



