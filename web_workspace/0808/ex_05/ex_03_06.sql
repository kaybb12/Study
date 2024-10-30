SELECT ProductName, ProductID FROM Products, Suppliers
where ProductID % 2 = 0 and  Suppliers.SupplierId % 2 = 1;