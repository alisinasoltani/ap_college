import sqlite3
import random
import string
import json
from datetime import datetime, timedelta

def generate_random_date(start_year=1950, end_year=2005):
    """Generate a random datetime between two years"""
    year = random.randint(start_year, end_year)
    month = random.randint(1, 12)
    day = random.randint(1, 28)
    return datetime(year, month, day)

def generate_users(cursor, num_users=15):
    """Generate users table data"""
    print("Creating users table...")
    cursor.execute('''CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        username VARCHAR(12) NOT NULL UNIQUE,
        pass VARCHAR(12) NOT NULL,
        created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
        role INTEGER DEFAULT 0,
        invitation_code VARCHAR(15) NOT NULL,
        invite_count INTEGER DEFAULT 0,
        invited_by VARCHAR(15),
        birthday DATE,
        national_code VARCHAR(10),
        email VARCHAR(50) NOT NULL,
        email_verified INTEGER DEFAULT 0
    )''')

    users = []
    for i in range(num_users):
        username = f"user{random.randint(1000, 9999)}"
        email = f"{username}@example.com"
        birthday = generate_random_date()
        invitation_code = ''.join(random.choices(string.ascii_uppercase + string.digits, k=10))
        national_code = f"{random.randint(10**9, (10**10)-1):010d}"

        cursor.execute('''INSERT INTO users 
            (username, pass, invitation_code, email, birthday, national_code)
            VALUES (?, ?, ?, ?, ?, ?)''',
            (username, 'pass123', invitation_code, email, 
             birthday.date().isoformat(), national_code))
        users.append(cursor.lastrowid)
    
    print(f"Inserted {num_users} users")
    return users

def generate_orders(cursor, user_ids, num_orders=50):
    """Generate orders table data"""
    print("\nCreating orders table...")
    cursor.execute('''CREATE TABLE IF NOT EXISTS orders (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        user_id INTEGER NOT NULL,
        currency VARCHAR(12) NOT NULL,
        type VARCHAR(8) NOT NULL,
        created_at DATETIME NOT NULL,
        accepted INTEGER DEFAULT 0,
        accepted_at DATETIME,
        sender VARCHAR(32) NOT NULL,
        receiver VARCHAR(32)
    )''')

    currencies = ['BTC', 'ETH', 'USD', 'EUR', 'GBP', 'IRR']
    order_types = ['buy', 'sell']
    
    for _ in range(num_orders):
        user_id = random.choice(user_ids)
        created_at = datetime.now() - timedelta(days=random.randint(0, 365))
        accepted = random.choice([0, 1])
        accepted_at = created_at + timedelta(hours=1) if accepted else None
        sender = '0x' + ''.join(random.choices(string.hexdigits, k=32))
        receiver = '0x' + ''.join(random.choices(string.hexdigits, k=32)) if accepted else None

        cursor.execute('''INSERT INTO orders 
            (user_id, currency, type, created_at, accepted, accepted_at, sender, receiver)
            VALUES (?, ?, ?, ?, ?, ?, ?, ?)''',
            (user_id, 
             random.choice(currencies),
             random.choice(order_types),
             created_at.isoformat(),
             accepted,
             accepted_at.isoformat() if accepted_at else None,
             sender,
             receiver))
    
    print(f"Inserted {num_orders} orders")

def generate_requests(cursor, user_ids):
    """Generate requests table data"""
    print("\nCreating requests table...")
    cursor.execute('''CREATE TABLE IF NOT EXISTS requests (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        user_id INTEGER NOT NULL,
        birthday DATE NOT NULL,
        national_code VARCHAR(10) NOT NULL
    )''')

    for user_id in user_ids:
        birthday = generate_random_date()
        national_code = f"{random.randint(10**9, (10**10)-1):010d}"

        cursor.execute('''INSERT INTO requests 
            (user_id, birthday, national_code)
            VALUES (?, ?, ?)''',
            (user_id, birthday.date().isoformat(), national_code))
    
    print(f"Inserted {len(user_ids)} requests")

def generate_wallets(cursor, user_ids):
    """Generate wallets table data"""
    print("\nCreating wallets table...")
    cursor.execute('''CREATE TABLE IF NOT EXISTS wallets (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        user_id INTEGER NOT NULL,
        safe_word VARCHAR(6) NOT NULL,
        created_at DATETIME NOT NULL,
        public_add VARCHAR(32) NOT NULL,
        currencies TEXT NOT NULL
    )''')

    for user_id in user_ids:
        safe_word = ''.join(random.choices(string.ascii_uppercase + string.digits, k=6))
        created_at = datetime.now() - timedelta(days=random.randint(0, 100))
        public_add = '0x' + ''.join(random.choices(string.hexdigits, k=40))
        
        # Generate random currency balances
        currencies = {
            "BTC": round(random.uniform(0.1, 5.0), 8),
            "ETH": round(random.uniform(1.0, 20.0), 6),
            "USD": round(random.uniform(1000.0, 50000.0), 2)
        }

        cursor.execute('''INSERT INTO wallets 
            (user_id, safe_word, created_at, public_add, currencies)
            VALUES (?, ?, ?, ?, ?)''',
            (user_id, 
             safe_word,
             created_at.isoformat(),
             public_add,
             json.dumps(currencies)))
    
    print(f"Inserted {len(user_ids)} wallets")

def verify_data(cursor):
    """Verify the inserted data"""
    print("\nVerifying data...")
    tables = ['users', 'orders', 'requests', 'wallets']
    for table in tables:
        cursor.execute(f"SELECT COUNT(*) FROM {table}")
        count = cursor.fetchone()[0]
        print(f"{table.capitalize()}: {count} records")

def main():
    # Connect to SQLite database
    conn = sqlite3.connect('cobitex.db')
    cursor = conn.cursor()

    try:
        # Generate all data
        user_ids = generate_users(cursor)
        generate_orders(cursor, user_ids)
        generate_requests(cursor, user_ids)
        generate_wallets(cursor, user_ids)
        
        # Commit changes
        conn.commit()
        
        # Verify data
        verify_data(cursor)
        
    except Exception as e:
        print(f"Error: {str(e)}")
        conn.rollback()
    finally:
        conn.close()

if __name__ == "__main__":
    main()
    print("\nDatabase population complete! File: cobitex.db")