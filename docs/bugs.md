# Chromatic-cute [![Build Status](https://travis-ci.org/Texas-C/Chromatic-cute.svg?branch=master)](https://travis-ci.org/Texas-C/Chromatic-cute)

A game about arranging colors. Qt rewrite version of `Chromatic` (original by https://github.com/halfsail/Chromatic)

[Coding Status]: `v 0.1`

## Dependencies:

	Qt

## install dependencies (etc. Ubuntu 18.04):

	sudo apt install qt5-default libqjson-dev

# Change History:

* V0.1: basic function complete

# TODO:

1. GUI: Main menu / puzzle page [done]
2. Tutorial
3. puzzle editor


# Fixed bug:

* puzzle `soil` 's data not found, so removed it from resource.
* rectangle no response when clicked.

Original `PuzzleRectItem` inherits from `QGraphicsItem`. And I added a member `m_rect` for drawing. However, those rectangle didn't draw or response mouse press event some time. (that's weird)

# issues:

* Level 1 frozen on init. (critical issue) (solved(temperary))
* Rectangle/blocks didn't handle mouse press event.
* Some of rectangle didn't draw on graphics view (maybe cause by resize);

This bug caused by `QStackedWidget` & `QGarphicsItem`

While `QGraphicsView` is not set as current `QStackWidget` at inital. Item couldn't grab mouse press event after stacked widget switch to graphics view. (so.. reason unknow)

* Last level crash
