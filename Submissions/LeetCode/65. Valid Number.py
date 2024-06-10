class Solution:
    def isDecimal(self, s):
        if s == "":
            return False
        if s[0] == '+' or s[0] == '-':
            s = s[1:]

        parts = s.split('.')
        if len(parts) != 2:
            return False
        
        s1 = parts[0]
        s2 = parts[1]
        if s1 == "":
            return s2.isnumeric()
        elif s2 == "":
            return s1.isnumeric()
        else:
            return s1.isnumeric() and s2.isnumeric()

    def isInteger(self, s):
        if s == "":
            return False
        if s[0] == '+' or s[0] == '-':
            s = s[1:]

        return s.isnumeric();

    def isNumber(self, s: str) -> bool:
        if s == "":
            return False
        s = s.lower()
        for c in s:
            if c not in "0123456789+-.e":
                return False
        
        parts = s.split('e')
        if (len(parts) > 2):
            return False
        elif len(parts) == 1:
            s = parts[0]
            return self.isDecimal(s) or self.isInteger(s)
        elif len(parts) == 2:
            s1 = parts[0]
            s2 = parts[1]
            return (self.isDecimal(s1) or self.isInteger(s1)) and self.isInteger(s2)

        return True
    
