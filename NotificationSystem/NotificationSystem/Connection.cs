using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.OleDb;

namespace NotificationSystem
{

    public class Connection
    {
        private static Connection instance;
        string DBPath;
        OleDbConnection connection;

        private Connection() 
        {
            DBPath = "C:\\Users\\srisai\\Documents\\NotificationDB.accdb";
            connection = new OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0;Data Source="+DBPath+";Persist Security Info=False;");            
        }

        public static Connection Instance
        {
            get
            {
                if (instance == null)
                {
                    instance = new Connection();
                }
                return instance;
            }
        }

        public bool InsertUser(string username,string email, string mobile, string password)
        {
            using (OleDbCommand cmd = new OleDbCommand("Select count(*) from Userstbl where UserName = '"+username+"';", connection))
            {
                connection.Open();
                if ((int)cmd.ExecuteScalar() > 0)
                {
                    connection.Close();
                    return false;
                }
                connection.Close();
            }
            
            using (OleDbCommand cmd = new OleDbCommand("INSERT INTO Userstbl(UserName, email,Mobile,[Password]) VALUES ('" + username + "','" + email + "','" + mobile + "','" + password + "');", connection))
            {
                connection.Open();
                cmd.ExecuteNonQuery();
                connection.Close();
            }
            return true;
        }

        public bool isAuthendicate(string username, string password)
        {
            using (OleDbCommand cmd = new OleDbCommand("Select count(*) from Userstbl where UserName = '" + username + "' and [password] = '"+password+"';", connection))
            {
                connection.Open();
                if ((int)cmd.ExecuteScalar() <= 0)
                {
                    connection.Close();
                    return false;
                }
                connection.Close();
            }
            return true;
        }

        public List<string> selectItemRange(int from, int to)
        {
            List<string> lst = new List<string>();
            using (OleDbCommand cmd = new OleDbCommand("SELECT TOP " + to + " ItemID FROM Items ORDER BY LastlyUpdated DESC;", connection))
            {
                connection.Open();
                OleDbDataReader reader = cmd.ExecuteReader();
                int cnt = 0;
                while (reader.Read())
                {
                    cnt++;
                    if (cnt < from)
                        continue;
                    lst.Add(reader[0].ToString());
                }
                connection.Close();
            }
            return lst;
        }

        public string selectItemDetails(string itemID)
        {
            StringBuilder str = new StringBuilder();
            using (OleDbCommand cmd = new OleDbCommand("SELECT AttributeName,AttributeValue FROM ItemDetails WHERE ItemID = '"+itemID+"';", connection))
            {
                connection.Open();
                OleDbDataReader reader = cmd.ExecuteReader();               
                while (reader.Read())
                {
                    str.AppendFormat("{0}\t\t : {1}\n", reader[0].ToString(), reader[1].ToString());
                }
                connection.Close();
            }
            return str.ToString();
        }

        public List<string> GetConditions(string UserName)
        {
            List<string> lst = new List<string>();
            using (OleDbCommand cmd = new OleDbCommand("SELECT Conditions FROM Conditions WHERE ID IN (SELECT ID from Userstbl WHERE UserName ='" + UserName + "');", connection))
            {
                connection.Open();
                OleDbDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    lst.Add(reader[0].ToString());
                }
                connection.Close();
            }
            return lst;
        }

        ~Connection()
        {
            
        }
    }
}
