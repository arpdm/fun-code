#!/usr/bin/env python3

"""
    Description:

        - ISS Tracker using open-notify API
        - List of all current Astronauts in space

    Useful Links:

        http://www.satsig.net/lat_long.htm

"""

import requests
import pandas as pd
from mpl_toolkits.basemap import Basemap
import matplotlib.pyplot as plt

GET_ASTRONAUT_IN_SPACE = "http://api.open-notify.org/astros.json"
GET_ISS_LOCATION = "http://api.open-notify.org/iss-now.json"


def get_list_of_astronauts_in_space():
    """
    Print list of astronauts currently in space
    """
    api_response = requests.get(url=GET_ASTRONAUT_IN_SPACE).json()
    astronauts_in_space = api_response["people"]

    for astronout in astronauts_in_space:
        print(astronout["name"])


def geo_coordinates_to_pixels(max_x_pixels, max_y_pixels, longitude, latitude):
    """
    Convert latitude and langitude and return pixel coordinates
    """
    x_location = ((longitude + 180) / 360) * max_x_pixels
    y_location = ((latitude - 90) / 180) * max_y_pixels
    return x_location, y_location


def track_iss():
    """
    Get current coordinates of ISS
    """
    api_response = requests.get(url=GET_ISS_LOCATION).json()
    iss_longitude = float(api_response["iss_position"]["longitude"])
    iss_latitude = float(api_response["iss_position"]["latitude"])
    return (iss_longitude, iss_latitude)


def overlay_iss_location_on_geo_map():
    """
    Using basemap, spot the ISS on geo map
    """
    plt.figure(figsize=(16, 8))
    plt.title("ISS Location", fontsize=30)

    # Put a backgroun map in matplot lib figure using basemap
    geo_map = Basemap(llcrnrlon=-180, llcrnrlat=-65, urcrnrlon=180, urcrnrlat=80)
    geo_map.drawmapboundary(fill_color="#A6CAE0", linewidth=0)
    geo_map.fillcontinents(color="green", alpha=0.3)
    geo_map.drawcoastlines(linewidth=0.1, color="white")

    # Get the ISS Location and overlay it on geomap
    iss_longitude, iss_latitude = track_iss()
    geo_map.scatter(iss_longitude, iss_latitude, s=200, alpha=0.4, color="red")

    plt.show()


get_list_of_astronauts_in_space()
overlay_iss_location_on_geo_map()
