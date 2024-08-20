select Name, CountryCode from city
where Population >= 100 * 10000 and Population <= 200 * 10000 and CountryCode = 'JPN';
