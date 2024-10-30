SELECT * FROM Orders, Shippers
WHERE OrderID < 10000 or Shippers.ShipperID < 5;