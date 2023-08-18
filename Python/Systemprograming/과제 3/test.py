if radio_button is self.bigben:
    if MyWindow.change == 1:
        MyWindow.change = 0
        self.bigben_Remove_backgrounds(new_img, filename, value=MyWindow.value)
    else:
        self.bigben_Remove_backgrounds(new_img, filename, value=167)
elif radio_button is self.cat:
    if MyWindow.change == 1:
        MyWindow.change = 0
        self.cat_Remove_backgrounds(new_img, filename, value=MyWindow.value)
    else:
        self.cat_Remove_backgrounds(new_img, filename, value=99)
elif radio_button is self.duck:
    if MyWindow.change == 1:
        MyWindow.change = 0
        self.duck_Remove_backgrounds(new_img, filename, value=MyWindow.value)
    else:
        self.duck_Remove_backgrounds(new_img, filename, value=111)
elif radio_button is self.tomato:
    if MyWindow.change == 1:
        MyWindow.change = 0
        self.tomato_Remove_backgrounds(new_img, filename, value=MyWindow.value)
    else:
        self.tomato_Remove_backgrounds(new_img, filename, value=80)
elif radio_button is self.trafficlight:
    if MyWindow.change == 1:
        MyWindow.change = 0
        self.trafficlight_Remove_backgrounds(new_img, filename, value=MyWindow.value)
    else:
        self.trafficlight_Remove_backgrounds(new_img, filename, value=61)