class MyTime:  #MyTime.py
    def __init__(self, h=0, m=0):
        self.hours=h
        self.minutes=m

    def __add__(self, other):
        if isinstance(other, int):
            total_min=self.minutes+other
            new_hours=self.hours+total_min//60
            new_minutes=total_min%60
            return MyTime(new_hours, new_minutes)
        return NotImplemented

    def __radd__(self, other):
        return self.__add__(other)

    def __str__(self):
        return f"{self.hours} hours and {self.minutes} minutes."

if__name__=="__main__":
    mt=MyTime(1, 59)
    print(mt+2)
    print(1+mt)
