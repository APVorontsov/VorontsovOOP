class Named
{
public:
	Named( std::string const & name )
		: m_Name( name )
	{};

protected:
	std::string m_Name;
};

class Printable : public Named
{
public:
	virtual std::string Print() = 0;
	Printable( std::string const & name )
		: Named( name )
	{};
};