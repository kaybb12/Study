SELECT OrderDetailID as '상세주문번호', OrderID as '주문번호', ProductID as '상품번호', Quantity as '수량' FROM OrderDetails 
where OrderID <= 10000 or ProductID >= 50 
order by OrderDetailID DESC limit 8